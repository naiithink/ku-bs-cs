package th.ku.naiithink.cs211.lessons.strategy.mails;

import java.util.Optional;

public final class CaesarCipher implements CipherAlgo<String, Integer> {

    private static final boolean REQUIRED_KEYS = true;

    @Override
    public boolean requiredKeys() {
        return REQUIRED_KEYS;
    }

    @Override
    public String encrypt(String data, Optional<Integer> key) {
        if (key.isEmpty()) {
            System.err.println("Key is required.");
            return null;
        }

        String res = new String();
        StringBuffer resBuff = new StringBuffer(data.length());
        int keyInt = key.get();

        for (int i = 0; i < data.length(); i++) {
            resBuff.append((char) (data.charAt(i) + keyInt));
        }

        res = resBuff.toString();

        return res;
    }

    @Override
    public String decrypt(String data, Optional<Integer> key) {
        if (key.isEmpty()) {
            System.err.println("Key is required.");
            return null;
        }

        String res = new String();
        StringBuffer resBuff = new StringBuffer(data.length());
        int keyInt = key.get();

        for (int i = 0; i < data.length(); i++) {
            resBuff.append((char) (data.charAt(i) - keyInt));
        }

        res = resBuff.toString();

        return res;
    }
}
