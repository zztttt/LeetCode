pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int size = 0;
int capacity = 10;
int buffer[capacity];

int main(int argc, char **argv)
{
    pthread_t producer_id;
    pthread_t consumer_id;

    pthread_create(&producer_id, NULL, producer, NULL);
    pthread_create(&consumer_id, NULL, consumer, NULL);
    sleep(1);

    return 0;
}

void* producer(void *arg){
    pthread_detach(pthread_self());
    while(true){
        pthread_mutex_lock(&mutex);
        while(size == capacity){
            pthread_cond_wait(&cond, &mutex);
        }
        // produce
        size++;
        if(size == 1)
            pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

void reducer(void* arg){
    pthread_detach(pthread_self());
    while(true){
        pthread_mutex_lock(&mutex);
        while(size == 0){
            pthread_cond_wait(&cond, &mutex);
        }
        // consume
        size--;
        if(size == capacity - 1){
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&mutex);
    }
}