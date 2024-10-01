fun main() {
    repeat(readln().toInt()) {
        val n = readln().toInt()
        val a = readln().split(" ").map { it.toInt() }
        val x = a.dropLast(1).max()
        if (a[n - 1] == x + 1) {
            println(x)
        } else {
            println("Ambiguous")
        }
    }
}
