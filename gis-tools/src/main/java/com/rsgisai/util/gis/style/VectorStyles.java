package com.rsgisai.util.gis.style;

import com.rsgisai.geohazard.system.common.entity.Legend;
import lombok.extern.slf4j.Slf4j;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * @author tfh, created at 2023-05-09 9:30 AM
 */
@Slf4j
public class VectorStyles {

    public static void main(String[] args) throws ParserConfigurationException, IOException, SAXException {
        InputStream inputStream = VectorStyles.class.getClassLoader().getResourceAsStream("style/exposure_index.sld");
        List<Legend> legendList = parse(inputStream);
        for (Legend legend : legendList) {
            System.out.println("legend = " + legend);
        }
    }


    public static List<Legend> parse(InputStream inputStream) throws ParserConfigurationException, IOException, SAXException {

        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.parse(inputStream);
        doc.getDocumentElement().normalize();

        NodeList fillPotentialNodeList = doc.getElementsByTagName("se:SvgParameter");
        NodeList labelNodeList = doc.getElementsByTagName("se:Title");

        List<Legend> result = new ArrayList<>();
        for (int i = 0; i < fillPotentialNodeList.getLength(); i++) {
            Node item = fillPotentialNodeList.item(i);
            NamedNodeMap namedNodeMap = item.getAttributes();
            if ("fill".equals(namedNodeMap.getNamedItem("name").getNodeValue())) {
                String rgbText = item.getTextContent();
                System.out.println("textContent = " + rgbText);

                Legend legend = new Legend();
                legend.setRgb(rgbText);
                result.add(legend);
            }
        }
        for (int i = 0; i < labelNodeList.getLength(); i++) {
            Node label = labelNodeList.item(i);
            String labelTest = label.getTextContent();
            Legend legend = result.get(i);
            legend.setLabel(labelTest);
            legend.setValue(labelTest);
            result.add(legend);
        }

        return result;
    }

    public static List<Legend> parse(String name, InputStream inputStream) throws ParserConfigurationException, IOException, SAXException {
        List<Legend> legendList = parse(inputStream);
        legendList.forEach((legend) -> legend.setName(name));
        return legendList;
    }
}
