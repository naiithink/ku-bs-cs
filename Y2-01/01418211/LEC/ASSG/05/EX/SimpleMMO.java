package EX05;

import EX05.Player;
import java.util.Arrays;

public class SimpleMMO {
    public static void main(String[] args) {
        Player p1 = new Player("p1",100, 1);
        Player p2 = new Player("p2",300, 3);
        Player p3 = new Player("p3",200, 2);

        Player [] clan_server1 = {p1, p2, p3};
        Player [] clan_server2 = new Player[clan_server1.length];

        for (int i = 0, len = clan_server1.length; i < len; i++) {
            try {
                clan_server2[i] = (Player) clan_server1[i].clone();
            } catch (CloneNotSupportedException err) {
                System.err.println(err);
            }
        }

        clan_server2[2].setName("bot1");

        System.out.println(Arrays.toString(clan_server1));
        System.out.println(Arrays.toString(clan_server2));

        // Arrays.sort(clan_server2);
        Arrays.sort(clan_server2);
        System.out.println(Arrays.toString(clan_server2));
    }
}
