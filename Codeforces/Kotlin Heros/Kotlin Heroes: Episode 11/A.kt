fun main() {
    repeat(readInt()) {
        val n = readln.toInt()
        val a = readStrings().map { it.toInt() }
        val x = a.dropLast(1).max()
        if (a[n - 1] == x + 1) {
            println(x)
        } else {
            println("Ambiguous")
        }
    }
}
