fun main() {
    var t = readln().toInt()
    repeat(t) {
        var a = readln().split(" ").map { it.toInt() }
        val f: MutableMap<Int, Int> = mutableMapOf()
        f[a[0] + a[1]] = (f[a[0] + a[1]] ?: 0) + 1
        f[a[2] - a[1]] = (f[a[2] - a[1]] ?: 0) + 1
        f[a[3] - a[2]] = (f[a[3] - a[2]] ?: 0) + 1
        var ans = 0
        for ((_, v) in f) {
            ans = maxOf(ans, v)
        }
        println(ans)
    }
}
