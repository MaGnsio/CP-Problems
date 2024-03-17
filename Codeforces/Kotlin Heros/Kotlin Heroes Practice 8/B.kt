fun main() {
    var a1 = readLine()!!.toInt()
    var a2 = readLine()!!.toInt()
    var k1 = readLine()!!.toInt()
    var k2 = readLine()!!.toInt()
    var n = readLine()!!.toInt()
    var min = maxOf(0, n - ((k1 - 1) * a1 + (k2 - 1) * a2))
    if (k1 > k2) {
        a1 = a2.also{a2 = a1}
        k1 = k2.also{k2 = k1}
    }
    var max: Int
    if (n <= a1 * k1) {
        max = n / k1
    } else {
        max = (a1 + (n - a1 * k1) / k2)
    }
    print("$min $max")
}