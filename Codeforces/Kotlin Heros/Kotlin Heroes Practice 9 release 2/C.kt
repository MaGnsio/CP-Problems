fun readlnInt() = readln().toInt()
fun readlnStrings() = readln().split(' ')
fun readIntArray() = readlnStrings().run { IntArray(size) { get(it).toInt() } }

fun main() {
    val n = readlnInt()
    val a = readIntArray()
    val f = IntArray(101)
    for (i in 0 until 101) {
        f[i] = 0
    }
    for (i in 0 until n) {
        f[a[i]]++
    }
    val b = ArrayList<Int>()
    for (i in 0 until 101) {
        if (f[i] % 2 == 1) {
            b.add(i)
        }
    }
    var ans = 0
    for (i in 0 until b.size step 2) {
        ans += b[i + 1] - b[i]
    }
    println(ans)
}
