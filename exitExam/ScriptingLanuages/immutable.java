public class IntegerPair {
    private final int x;
    private final int y;

    IntegerPair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

IntegerPair p = new IntegerPair(5, 10);

p.x = 50;
// Compilation error: cannot assign a value to a final variable