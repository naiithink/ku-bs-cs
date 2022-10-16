package th.ku.naiithink.cs211.lessons.strategy.mails;

import java.util.Optional;

public interface CipherAlgo<T, U> {

    boolean requiredKeys();

    T encrypt(final T data, final Optional<U> key);

    T decrypt(final T data, final Optional<U> key);
}
