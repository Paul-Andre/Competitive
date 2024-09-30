import kotlin.math.max
import kotlin.math.min


private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int
private fun readLongs() = readStrings().map { it.toLong() } // list of int


fun main(args : Array<String>) {
    val t = readln().toInt();
    repeat (t) {
        val (n,h,b) = readLongs();
        var line1 = readStr();
        var line2 = readStr();
        if ('S' in line2) {
            val temp = line1
            line1 = line2
            line2 = temp;
        }
        val sheepPos = line1.indexOf('S')
        assert(sheepPos != -1);
        val wolvesLeft = (
                line1.substring(0, sheepPos).count { it == 'W' } + line2.substring(0, sheepPos).count { it == 'W' })
        val wolvesRight =  (
                line1.substring(sheepPos).count { it == 'W' } + line2.substring(sheepPos).count { it == 'W' })
//        System.err.println(wolvesLeft);
//        System.err.println(wolvesRight);



        var best = 3*b;
        best = min(best,2*b + wolvesRight*h);
        best = min(best,2*b + wolvesLeft*h);
        best = min(best,wolvesLeft*h + wolvesRight*h);
        println(best);







    }

}