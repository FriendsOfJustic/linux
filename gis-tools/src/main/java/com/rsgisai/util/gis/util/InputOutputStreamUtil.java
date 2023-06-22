package com.rsgisai.util.gis.util;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * @author tfh, created at 2023-02-16 3:25 PM
 */
public class InputOutputStreamUtil {
    public static void copy(InputStream source, OutputStream target) throws IOException {
        byte[] buf = new byte[8192];
        int length;
        while ((length = source.read(buf)) != -1) {
            target.write(buf, 0, length);
        }
        target.flush();
    }
}
