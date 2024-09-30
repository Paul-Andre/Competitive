

private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int


fun main(args : Array<String>) {
    var t = readln().toInt();
    repeat (t) {
        var n = readln().toInt();
        var D = ArrayList(readInts());
        var last = D.last();
        var maxBefore = D.subList(0, D.size-1).max();
        if (maxBefore==last-1) {
            println(maxBefore)
        } else {
            println("Ambiguous")
        }
    }

}