import kotlin.collections.*
import kotlin.io.*
import kotlin.math.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        var T = inp.readlnInt()
        while(T-- > 0){
            var (n,k,x,y) = inp.readlnInts()
            var a = IntArray(n){0}
            var i = 0
            for (value in inp.readlnInts()){
                a[i++] = value
            }
            a.sort()
            a.reverse()
            var sum = 0
            a.forEach { sum += it }
            var ans = x * a.filter{it > k}.count()
            print("$ans\n")
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