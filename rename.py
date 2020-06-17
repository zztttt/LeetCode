import os

path = "D:\GitHubRepo\LeetCode"
# print("a" + path)
dirs = os.listdir(path)
for file in dirs:
    if file[3] == '.':
        #print(file)
        olddir = os.path.join(path, file)
        print(olddir)
        newdir = path + "\\" + "0" + file
        print(newdir)
        os.rename(olddir, newdir)
    
    
