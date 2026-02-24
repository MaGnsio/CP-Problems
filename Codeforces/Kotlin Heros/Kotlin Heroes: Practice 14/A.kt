fun main() {
    var t = readln().toInt()
    repeat(t) {
        var n = readln().toInt()
        var a = readln().split(" ").map { it.toInt() }
        var f = IntArray(n)
        for (i in 0 until n) {
            f[a[i] - 1]++
        }
        var score = 0
        for (i in 0 until n) {
            score += f[i] / 2
        }
        println(score)
    }
}
