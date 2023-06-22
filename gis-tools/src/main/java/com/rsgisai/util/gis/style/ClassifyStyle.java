package com.rsgisai.util.gis.style;

import com.rsgisai.util.gis.util.ColorUtils;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * @author tfh, created at 2023-02-20 10:18 AM
 */
public class ClassifyStyle {

    public static void main(String[] args) throws IOException {
        InputStream resourceAsStream = ClassifyStyle.class.getClassLoader()
                .getResourceAsStream("reclassify_template.sld");
        InputStreamReader inputStreamReader = new InputStreamReader(resourceAsStream);
        BufferedReader reader = new BufferedReader(inputStreamReader);
        String line;
        StringBuilder response = new StringBuilder();
        while ((line = reader.readLine()) != null) {
            response.append(line);
            response.append(System.getProperty("line.separator"));
        }
        String s = response.toString();
        System.out.println("s = " + s);
    }

    private static String colormapTemplate;

    private static String sldTemplate;

    static {
        colormapTemplate = readFileInClasspath("colormap_entry_template.sld");
        sldTemplate = readFileInClasspath("reclassify_template.sld");
    }

    private static String readFileInClasspath(String templateFilename) {
        InputStream resourceAsStream = ClassifyStyle.class.getClassLoader()/*注意必须使用classloader才可以正确加载资源文件*/
                .getResourceAsStream(templateFilename);
        InputStreamReader inputStreamReader = new InputStreamReader(resourceAsStream);
        BufferedReader reader = new BufferedReader(inputStreamReader);
        String line;
        StringBuilder response = new StringBuilder();
        while (true) {
            try {
                if (!((line = reader.readLine()) != null)) break;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            response.append(line);
            response.append(System.getProperty("line.separator"));
        }
        String s = response.toString();
        return s;
    }

    String generateClassifySld(String styleName, int n) throws IOException {
        StringBuilder colorMapEntryList = new StringBuilder();
        List<String> rgbHexList = generateRgbHexList(n);
        for (int i = 0; i < n; i++) {
            int I = i + 1;
            String colorMapEntry = colormapTemplate
                    .replace("${quantity}", String.valueOf(I))
                    .replace("${label}", String.valueOf(I))
                    .replace("${color}", rgbHexList.get(i));
            colorMapEntryList.append(colorMapEntry);
        }
        return sldTemplate
                .replace("${styleName}", styleName)
                .replace("${colorMapEntryList}", colorMapEntryList);
    }

    List<String> generateRgbHexList(int n) {
        float hue = 0; // 色相值
        float saturation = 1f; // 饱和度值
        float value = 1f; // 值（亮度）值
        float deltaHue = 360f / n;
        ArrayList<String> strings = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            strings.add(ColorUtils.getRgbHex(hue, saturation, value));
            hue += deltaHue;
        }
        return strings;
    }

}
