/**
 * The Interval represents an Interval in its most mathematically pure
 * form.
 * 
 * @author Sugaku
 */
public record Interval (int a, int b) {
    
    /**
     * Checks whether *this* interval is a subset of the given
     * interval. Non-strict subset.
     * 
     * @param i The interval to check if it contains this one.
     * @return True if and only if this is a subset of i.
     */
    public boolean subset (Interval i) {
        return a >= i.a && b <= i.b;
    }
    
    /**
     * Checks whether *this* interval has an nonempty intersection
     * with the given interval.
     * 
     * @param i The interval to intersect with this one. 
     * @return Ture if and only if this interval has a nonempty
     * intersection with i.
     */
    public boolean nonemptyIntersection (Interval i) {
        return (i.a <= a && a <= i.b) || (i.a <= b && b <= i.b);
    }

    public String tString () {
        return "[" + a + "," + b + "]";
    }
}
