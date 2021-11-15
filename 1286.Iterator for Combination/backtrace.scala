class CombinationIterator(_characters: String, _combinationLength: Int) {
    import scala.collection.mutable.ArrayBuffer;
    private var index: Int = 0;
    private var combinations: ArrayBuffer[String] = ArrayBuffer[String]();
    private var visited: ArrayBuffer[Char] = ArrayBuffer[Char]();
    
    backtrace(_characters, _combinationLength, 0, visited);
    
    
    def backtrace(characters: String, combinationLength: Int, start: Int, visited: ArrayBuffer[Char]){
        if(visited.length == combinationLength){
            combinations.append(visited.mkString(""));
            return;
        }
        var i = 0;
        var len = characters.length();
        for(i <- start until len){
            var cur: Char = characters.charAt(i);
            if(!visited.contains(cur)){
                visited.append(cur);
                backtrace(characters, combinationLength, i + 1, visited);
                visited.remove(visited.length() - 1);
            }
        }
    }

    def next(): String = {
        if(hasNext()){
            var old: Int = index;
            index += 1;
            return combinations(old);
        }
        assert(false);
        return "";
    }

    def hasNext(): Boolean = {
        if(index < combinations.length)
            return true;
        return false;
    }

}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * var obj = new CombinationIterator(characters, combinationLength)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */