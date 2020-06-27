import kotlin.collections.*
import kotlin.io.*
import kotlin.math.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        val t = inp.readlnInt()
        var pw = 1
        var ar = mutableListOf <Int> ()
        while(pw < 10000){
            ar.addAll((1..9).map{it * pw})
            pw *= 10
        }
        ar.add(pw)
        for(test in 1..t){
            var n = inp.readlnInt()
            var ans = mutableListOf <Int> ()
            while(n > 0){
                for(i in ar.size - 1 downTo 0 step 1){
                    if(ar.get(i) <= n){
                        n -= ar.get(i)
                        ans.add(ar.get(i))
                        break
                    }
                }
            }
            println(ans.size)
            ans.forEach{ print("$it ")}
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