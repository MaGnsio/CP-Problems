fun readlnInt() = readln().toInt()
fun readlnStrings() = readln().split(' ')
fun readIntArray() = readlnStrings().run { IntArray(size) { get(it).toInt() } }

fun main() {
    val nax : Int = 200005
    val n = readlnInt()
    val a = readIntArray()
    val f = IntArray(nax)
    for (i in 0 until n) {
        f[a[i]]++
    }
    var ok : Boolean = true
    val b = ArrayList<Int>()
    val c = ArrayList<Int>()
    for (i in 0 until nax) {
        if (f[i] == 0) {
            continue
        } else if (f[i] == 1) {
            b.add(i)
        } else if (f[i] == 2) {
            b.add(i)
            c.add(i)
        } else {
            ok = false
        }
    }
    c.reverse()
    if (ok) {
        println("YES")
        println(b.size)
        for (i in 0 until b.size) {
            print(b[i])
            print(" ")
        }
        println()
        println(c.size)
        for (i in 0 until c.size) {
            print(c[i])
            print(" ")
        }
    } else {
        println("NO")
    }

}
