

private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int


fun main(args : Array<String>) {
    var t = readln().toInt();
    repeat (t) {
        var n = readln().toInt();
        print(1)
        print(" ")
        for (i in n downTo 2) {
            print(i)
            print(" ")
        }

    }

}