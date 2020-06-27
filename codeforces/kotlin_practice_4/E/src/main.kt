import kotlin.collections.*
import kotlin.io.*
import kotlin.math.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        val t = inp.readlnInt()
        for(test in 1..t){
            val n = inp.readlnInt()
            if(n < 4){
                println("-1")
                continue
            }
            val ans = mutableListOf<Int> ()
            ans.addAll((n downTo 1).filter{it and 1 == 1})
            ans.addAll((4 downTo 2 step 2))
            ans.addAll((6..n).filter{it and 1 == 0})
            ans.forEach{print("$it ")}
            println()
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