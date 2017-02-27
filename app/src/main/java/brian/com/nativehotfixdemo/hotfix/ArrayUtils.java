package brian.com.nativehotfixdemo.hotfix;

import brian.com.nativehotfixdemo.annotations.MethodHotfix;

/**
 * Created by Xiaochen on 21/02/2017.
 */

public class ArrayUtils {
    @MethodHotfix(className="brian.com.nativehotfixdemo.modules.ArrayUtils", methodName="sum")
    public int sum(int[] array) {
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }

        return sum;
    }
}
