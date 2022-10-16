package th.ku.naiithink.cs211.lessons.strategy.mails;

import java.util.Optional;

public final class SwitchCipher implements CipherAlgo<String, Integer> {

    private static final boolean REQUIRED_KEYS = false;

    @Override
    public boolean requiredKeys() {
        return REQUIRED_KEYS;
    }

    @Override
    public String encrypt(String data, Optional<Integer> key) {
        if (key.isPresent() && key.get() != 0) {
            System.err.println("No keys required, one supplied.");
            return null;
        }

        String res = new String();
        StringBuffer resBuf = new StringBuffer(data);

        for (int i = 0, lim = data.length() - 1; i < lim; i += 2) {
            char tmp = data.charAt(i);
            resBuf.setCharAt(i, data.charAt(i + 1));
            resBuf.setCharAt(i + 1, tmp);
        }

        res = resBuf.toString();

        return res;
    }

    @Override
    public String decrypt(String data, Optional<Integer> key) {
        if (key.isPresent() && key.get() != 0) {
            System.err.println("No keys required, one supplied.");
            return null;
        }

        String res = new String();
        StringBuffer resBuf = new StringBuffer(data);

        for (int i = 0, lim = data.length() - 1; i < lim; i += 2) {
            char tmp = data.charAt(i + 1);
            resBuf.setCharAt(i + 1, data.charAt(i));
            resBuf.setCharAt(i, tmp);
        }

        res = resBuf.toString();

        return res;
    }
}
