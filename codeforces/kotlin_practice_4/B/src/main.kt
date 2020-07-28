import kotlin.collections.*
import kotlin.io.*
import kotlin.math.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        val t = inp.readlnInt()
        for(test in 1..t){
            var (a1,b1) = inp.readlnInts()
            var (a2,b2) = inp.readlnInts()
            if(a1 == a2 && b1 + b2 == a1){
                println("Yes")
            } else if(a1 == b2 && b1 + a2 == a1){
                println("Yes")
            } else if(b1 == a2 && a1 + b2 == b1){
                println("Yes")
            } else if(b1 == b2 && a1 + a2 == b1){
                println("Yes")
            } else {
                println("No")
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