package brian.com.nativehotfixdemo.modules;

/**
 * Created by Xiaochen on 21/02/2017.
 */

public class ArrayUtils {
    public int sum(int[] array) {
        int sum = 0;
        for (int i = 0; i <= array.length; i++) {
            sum += array[i];
        }

        return sum;
    }
}
