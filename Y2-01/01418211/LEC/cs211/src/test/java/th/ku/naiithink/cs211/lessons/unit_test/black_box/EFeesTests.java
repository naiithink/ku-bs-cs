package th.ku.naiithink.cs211.lessons.unit_test.black_box;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

/**
 * EFees.class
 * 
 * Compiled from "EFees.java"
 * public class th.ku.naiithink.cs211.lessons.unit_test.black_box.EFees {
 *   static {};
 *   public th.ku.naiithink.cs211.lessons.unit_test.black_box.EFees(double);
 *   public double computeFeeOf(int);
 * }
 */
public class EFeesTests {

    private EFees eFeesInstance = new EFees(38.22);

    private final double DELTA = 0.01;

    /**
     * EP
     * d = 138
     */
    @Test
    public void testComputeFeeAt137() {
        assertEquals(483.47, eFeesInstance.computeFeeOf(137), DELTA);
    }

    @Test
    public void testComputeFeeAt275() {
        assertEquals(1_198.72, eFeesInstance.computeFeeOf(275), DELTA);
    }

    @Test
    public void testComputeFeeAt413() {
        assertEquals(1_863.68, eFeesInstance.computeFeeOf(413), DELTA);
    }

    /**
     * BVA
     */
    @Test
    public void testComputeFeeUpToLowerBound() {
        assertEquals(525.72, eFeesInstance.computeFeeOf(150), DELTA);
    }

    @Test
    public void testComputeFeeNearLowerBound() {
        assertEquals(675.44, eFeesInstance.computeFeeOf(151), DELTA);
        assertEquals(679.66, eFeesInstance.computeFeeOf(152), DELTA);
    }

    @Test
    public void testComputeFeeNearUpperBound() {
        assertEquals(1_722.00, eFeesInstance.computeFeeOf(399), DELTA);
        assertEquals(1_726.22, eFeesInstance.computeFeeOf(400), DELTA);
    }

    @Test
    public void testComputeFeeFromUpperBound() {
        assertEquals(1_810.64, eFeesInstance.computeFeeOf(401), DELTA);
    }
}
