fun readlnInt() = readln().toInt()
fun readlnStrings() = readln().split(' ')
fun readIntArray() = readlnStrings().run { IntArray(size) { get(it).toInt() } }

fun main() {
    val times = readlnInt()
    repeat(times) {
        val n = readlnInt()
        val a = readIntArray()
        val f = IntArray(101)
        for (i in 0 until 101) {
            f[i] = 0
        }
        for (i in 0 until n) {
            f[a[i]]++
        }
        var unique = 0
        for (i in 0 until 101) {
            if (f[i] == 1) {
                unique = i
            }
        }
        var ans = 0
        for (i in 0 until n) {
            if (a[i] == unique) {
                ans = i + 1
                break
            }
        }
        println(ans)
    }
}
