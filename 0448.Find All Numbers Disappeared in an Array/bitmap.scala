object Solution {
    import scala.collection.mutable.ArrayBuffer;
    def findDisappearedNumbers(nums: Array[Int]): List[Int] = {
        var len = nums.length;
        var bitmap = Array.fill[Boolean](len + 1)(false);
        bitmap(0) = true;
        nums.foreach(i => bitmap(i) = true);
        
        var ret = ArrayBuffer[Int]();
        var index = 0;
        bitmap.map(i => {if(!i) ret.addOne(index); index += 1;});
        ret.toList;
    }
}