import kotlin.collections.*
import kotlin.io.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        val T = inp.readlnInt()
        for(test in 1..T){
            var (n,m,a,b) = inp.readlnInts()
            if(a * n != b * m){
                println("NO")
            } else {
                var shift = 0
                val ans = Array(n){IntArray(m){0}}
                (1 until m).filter{(it * n) % m == 0}.forEach{shift = it}
                for(i in 0 until n){
                    (0 until a).map{it -> (it + i * shift) % m}.forEach{ans[i][it] = 1}
                }
                println("YES")
                ans.map{it.joinToString("")}.forEach{println(it)}
            }
        }
    }

    class InputReader{
        public fun readln() = readLine()!!
        public fun readlnInt() = readln().toInt()
        public fun readlnLong() = readln().toLong()
        public fun readlnDouble() = readln().toDouble()

        public fun readlnStrings() = readln().split(" ")
        public fun readlnInts() = readlnStrings().map{it.toInt()}
        public fun readlnLongs() = readlnStrings().map{it.toLong()}
        public fun readlnDoubles() = readlnStrings().map{it.toDouble()}
    }
}

fun main(args : Array <String>){
    Main().solve(Main.InputReader())
}