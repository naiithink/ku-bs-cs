package th.ku.naiithink.cs211.lessons.unit_test.black_box;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

/**
 * AD.class
 * 
 * Compiled from "AD.java"
 * public class th.ku.naiithink.cs211.lessons.unit_test.black_box.AD {
 *   protected th.ku.naiithink.cs211.lessons.unit_test.black_box.AD();
 *   public static boolean isLeapYear(int);
 * }
 */
public class ADTests {

    /**
     * AD
     * d = 4
     */
    @Test
    public void testIsLeapYearUnder100() {
        for (int i = 4; i < 100; i += 4) {
            assertTrue(AD.isLeapYear(i));
        }
    }

    /**
     * AD
     * d = 100
     */
    @Test
    public void testIsLeapYearAt100() {
        assertFalse(AD.isLeapYear(100));
    }

    @Test
    public void testIsLeapYearAt200() {
        assertFalse(AD.isLeapYear(200));
    }

    @Test
    public void testIsLeapYearAt300() {
        assertFalse(AD.isLeapYear(300));
    }

    @Test
    public void testIsLeapYearAt400() {
        assertTrue(AD.isLeapYear(400));
    }

    @Test
    public void testIsLeapYearAt500() {
        assertFalse(AD.isLeapYear(500));
    }

    @Test
    public void exceptionTesting() {
        Exception e1 = assertThrows(IllegalArgumentException.class,
                                    () -> AD.isLeapYear(0));

        System.out.println("e1: " + e1.getMessage());

        Exception e2 = assertThrows(IllegalArgumentException.class,
                                    () -> AD.isLeapYear(-1));

        System.out.println("e2: " + e2.getMessage());
    }
}
