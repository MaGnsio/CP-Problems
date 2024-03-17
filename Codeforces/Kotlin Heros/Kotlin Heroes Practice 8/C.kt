fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map {it.toInt()}
    val b = a.withIndex().sortedByDescending {it.value}
    var res = 0
    for (i in 0 until n) {
        res += b[i].value * i + 1
    }
    println(res)
    println(b.joinToString(" ") {"${it.index + 1}"})
}