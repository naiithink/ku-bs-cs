package th.ku.naiithink.cs211.lessons.unit_test.white_box;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

/**
 * 0  public int oddOrPos(int[] x) {
 * 1      int count = 0;
 * 2      for (int i = 0; i < x.length; i++) {
 * 3          if (x[i] % 2 == 1 || x[i] > 0) {
 * 4              count++;
 * 5          }
 * 6      }
 * 7      return count;
 * 8  }
 */
public class OddOrPosTests {

    private static OddOrPos instance = new OddOrPos();

    /**
     * Statements
     */
    @Test
    @DisplayName("Statements, this test MUST be failed")
    public void testNonNil() {
        assertEquals(4, instance.oddOrPos(new int[] { -3, -1, 0, 1, 4 }));
    }

    /**
     * Decision
     */
    @Test
    @DisplayName("Decision")
    public void testEven() {
        assertEquals(3, instance.oddOrPos(new int[] { 2, 4, 6 }));
    }

    @Test
    @DisplayName("Decision, this test MUST be failed")
    public void testNegativeOdd() {
        assertEquals(3, instance.oddOrPos(new int[] { -5, -3, -1 }));
    }

    @Test
    @DisplayName("Decision")
    public void testNegativeEven() {
        assertEquals(0, instance.oddOrPos(new int[] { -8, -6, -4 }));
    }

    @Test
    @DisplayName("Decision")
    public void testElse() {
        assertEquals(0, instance.oddOrPos(new int[] { -4, -2, 0 }));
    }

    /**
     * Loop coverage
     */
    @Test
    @DisplayName("Loop coverage")
    public void testNil() {
        assertEquals(0, instance.oddOrPos(new int[] {}));
    }

    @Test
    @DisplayName("Loop coverage")
    public void testSingleLoop() {
        assertEquals(1, instance.oddOrPos(new int[] { 1 }));
    }

    @Test
    @DisplayName("Loop coverage")
    public void testMultiLoop() {
        assertEquals(0, instance.oddOrPos(new int[] { -8, -6, -4, -2, 0 }));
    }
}
