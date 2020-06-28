import kotlin.collections.*
import kotlin.io.*
import kotlin.math.*
import kotlin.Array

class Main{

    fun solve(inp : InputReader) {
        var t = inp.readlnInt()
        while(t-- > 0){
            var (n,k1,k2) = inp.readlnInts()
            var s : String = inp.readln()
            var ans = 0
            var i = 0
            while(i < n){
                if(s[i] == '0'){
                    ++i
                    continue
                }
                var j = i
                while(j < n && s[j] == '1'){
                    ++j
                }
                --j
                if(j - i + 1 == 1){
                    ans += k1
                }
                else {
                    var f = k1
                    for(x in i..j){
                        ans += f
                        f = min(k1,k2 - f)
                    }
                }
                i = j + 1
            }
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