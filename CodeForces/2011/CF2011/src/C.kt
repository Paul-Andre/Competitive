import kotlin.math.max


private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int


fun main(args : Array<String>) {
    var t = readln().toInt();
    repeat (t) {
        var given = readStr()
        var blocks = given.split("+")
        var sum = blocks.first().toLong() + blocks.last().toLong();
        for (block in blocks.subList(1, blocks.size-1)) {
            var try1 = block.substring(0,1).toLong() + block.substring(1,block.length).toLong();
            var try2 = block.substring(0, block.length-1).toLong() + block.substring(block.length-1 , block.length).toLong();
            sum+=max(try1, try2);

        }
        println(sum);

    }

}