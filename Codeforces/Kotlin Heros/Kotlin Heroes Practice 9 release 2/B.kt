fun readlnInt() = readln().toInt()

fun main() {
    val n = readlnInt()
    val s = readln()
    var i = 0
    var add = 1
    var ans = ""
    while (i < n) {
        ans += s[i]
        i += add
        add += 1
    }
    println(ans)
}
