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
        val s = readStr();
        var coreScore = 0;
        for (i in 0 ..< (s.length-1)) {
            val botC = s[i];
            val nextBotC = s[i+1]
            val curPlayerC: Char = when (nextBotC) {
                'P' -> 'R'
                'R' -> 'S'
                'S' -> 'P'
                else -> {throw IllegalStateException()}
            }
            if ((curPlayerC.toString()+botC) in "RSPR"){
                coreScore+=1;
            } else if ((botC.toString()+curPlayerC) in "RSPR"){
                coreScore-=1
            }
        }

        coreScore+=1;

        val tot: Int
        when (s[0]) {
            'R' -> {
                val extra = max(0, 1-coreScore);
                tot = s.length + extra;
            }
            'S' -> {
                val extra = max(0, 1-(coreScore+1))
                tot = s.length + extra + 1;
            }
            else -> {
                assert(s[0] == 'P')
                val tot1: Int
                val tot2: Int
                run {
                    val extra = max(0, 1-(coreScore+2))
                    tot1 = s.length + extra + 2;
                }
                run {
                    val extra = max(0, 1-(coreScore))
                    tot2 = s.length + extra + 1;
                }

                tot = min(tot1, tot2);
            }
        }
        println(tot);


    }

}