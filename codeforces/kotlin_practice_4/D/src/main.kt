import kotlin.collections.*
import kotlin.io.*
import kotlin.math.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        val t = inp.readlnInt()
        for(test in 1..t){
            val n = inp.readlnInt()
            val a = inp.readlnInts()
            var pref_a : Int = 0
            var pref_b : Int = 0
            var sum_a : Int = 0
            var sum_b : Int = 0
            var l = 0
            var r = n - 1
            var f = 0
            var move = 0
            while(l <= r){
                var cur : Int = 0
                if(f == 0){
                    while(l < r && cur + a[l] <= pref_b){
                        cur += a[l]
                        ++l
                    }
                    pref_a = cur + a[l++]
                    sum_a += pref_a
                    ++move
                } else {
                    while(l < r && cur + a[r] <= pref_a){
                        cur += a[r]
                        --r
                    }
                    pref_b = cur + a[r--]
                    sum_b += pref_b
                    ++move
                }
                f = f xor 1
            }
            println("$move $sum_a $sum_b")
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