package th.ku.naiithink.lectures.iii;

import java.util.Scanner;

public class Grading {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("กรอกคะแนนรวม: ");
        int score = in.nextInt();
        System.out.print("กรอกคะแนนสอบรวม: ");
        int scoreExam = in.nextInt();
        System.out.print("สถานะการทําโปรเจค (true คือสําเร็จ / false คือไม่เสร็จ): ");
        boolean projectStatus = in.nextBoolean();
        System.out.print("จํานวนครั้งการขาดเรียน: ");
        int numAbsent = in.nextInt();
        System.out.println("Your grade: " + getGrade(score, scoreExam, projectStatus, numAbsent));
    }

    public static String getGrade(int totalScore, int examScore, boolean projectStatus, int numAbsent) {
        String grade;

        if (totalScore < 50 || examScore < 40 || numAbsent > 3)
            grade = "F";
        else if (!projectStatus)
            grade = "I";
        else
            if (totalScore >= 80)
                grade = "A";
            else if (totalScore >= 75)
                grade = "B+";
            else if (totalScore >= 70)
                grade = "B";
            else if (totalScore >= 65)
                grade = "C+";
            else if (totalScore >= 60)
                grade = "C";
            else if (totalScore >= 55)
                grade = "D+";
            else
                grade = "D";

        return grade;
    }
}
