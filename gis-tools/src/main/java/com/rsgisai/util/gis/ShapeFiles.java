package com.rsgisai.util.gis;

import com.rsgisai.util.gis.exception.MultiPolygonException;
import org.geotools.data.FileDataStore;
import org.geotools.data.FileDataStoreFinder;
import org.geotools.data.simple.SimpleFeatureCollection;
import org.geotools.data.simple.SimpleFeatureIterator;
import org.geotools.data.simple.SimpleFeatureSource;
import org.geotools.geojson.geom.GeometryJSON;
import org.geotools.geometry.jts.JTSFactoryFinder;
import org.locationtech.jts.geom.Geometry;
import org.locationtech.jts.geom.GeometryFactory;
import org.locationtech.jts.geom.MultiPolygon;
import org.locationtech.jts.geom.Polygon;
import org.locationtech.jts.io.ParseException;
import org.locationtech.jts.io.WKTReader;
import org.opengis.feature.simple.SimpleFeature;
import util.gis.exception.SinglePolygonException;

import java.io.File;
import java.io.IOException;
import java.io.StringWriter;
import java.util.List;

public class ShapeFiles {
    public static String toWktSinglePolygon(String path) throws IOException, SinglePolygonException {
        return toWktSinglePolygon(new File(path));
    }

    public static String toWktSinglePolygon(File file) throws IOException, SinglePolygonException {
        FileDataStore store = FileDataStoreFinder.getDataStore(file);
        SimpleFeatureSource featureSource = store.getFeatureSource();

        SimpleFeatureCollection features = featureSource.getFeatures();
        try (SimpleFeatureIterator iterator = features.features()) {

            if (!iterator.hasNext()) {
                throw new SinglePolygonException("shape file contains 0 record");
            }
            SimpleFeature simpleFeature = iterator.next();
            if (iterator.hasNext()) {
                throw new SinglePolygonException("shape file contains more then 1 record");
            }

            List<Object> attributes = simpleFeature.getAttributes();
            for (Object attribute : attributes) {
                if (attribute instanceof MultiPolygon) {
                    int numGeometries = ((MultiPolygon) attribute).getNumGeometries();
                    if (numGeometries != 1) {
                        throw new SinglePolygonException(numGeometries + " Polygons in MultiPolygon, expect 1.");
                    }
                    Geometry geometryN = ((MultiPolygon) attribute).getGeometryN(0);
                    return geometryN.toText();// 返回 WKT
                }
                if (attribute instanceof Polygon) {
                    return ((Polygon) attribute).toText();
                }
            }
            throw new SinglePolygonException("no geometry field in record");
        }
    }

    public static String toGeoJsonSinglePolygon(File file) throws IOException, SinglePolygonException {
        FileDataStore store = FileDataStoreFinder.getDataStore(file);
        SimpleFeatureSource featureSource = store.getFeatureSource();

        SimpleFeatureCollection features = featureSource.getFeatures();
        try (SimpleFeatureIterator iterator = features.features()) {

            if (!iterator.hasNext()) {
                throw new SinglePolygonException("shape file contains 0 record");
            }
            SimpleFeature simpleFeature = iterator.next();
            if (iterator.hasNext()) {
                throw new SinglePolygonException("shape file contains more then 1 record");
            }

            List<Object> attributes = simpleFeature.getAttributes();
            for (Object attribute : attributes) {
                if (attribute instanceof MultiPolygon) {
                    int numGeometries = ((MultiPolygon) attribute).getNumGeometries();
                    if (numGeometries != 1) {
                        throw new SinglePolygonException(numGeometries + " Polygons in MultiPolygon, expect 1.");
                    }
                    Geometry geometryN = ((MultiPolygon) attribute).getGeometryN(0);
                    return wkt2GeoJson(geometryN.toText());// 返回 WKT
                }
                if (attribute instanceof Polygon) {
                    return wkt2GeoJson(((Polygon) attribute).toText());
                }
            }
            throw new SinglePolygonException("no geometry field in record");
        } catch (ParseException e) {
            throw new RuntimeException(e);
        }
    }

    private static String wkt2GeoJson(String wkt) throws ParseException, IOException {
        WKTReader wktReader = new WKTReader(new GeometryFactory());
        Geometry read = wktReader.read(wkt);
        GeometryJSON geometryJSON = new GeometryJSON();
        StringWriter stringWriter = new StringWriter();
        geometryJSON.write(read, stringWriter);
        return stringWriter.toString();
    }

    public static String toWktMultiPolygon(File file) throws IOException, MultiPolygonException {
        FileDataStore store = FileDataStoreFinder.getDataStore(file);
        SimpleFeatureSource featureSource = store.getFeatureSource();

        SimpleFeatureCollection features = featureSource.getFeatures();
        try (SimpleFeatureIterator iterator = features.features()) {
            // 确保 shp 文件只有一条记录
            if (!iterator.hasNext()) {
                throw new MultiPolygonException("shape file contains 0 record");
            }
            SimpleFeature simpleFeature = iterator.next();
            if (iterator.hasNext()) {
                throw new MultiPolygonException("shape file contains more then 1 record");
            }

            // 从shp的字段中提取 空间字段
            List<Object> attributes = simpleFeature.getAttributes();
            for (Object attribute : attributes) {
                // 如果是 MultiPolygon 则转换为Wkt返回
                if (attribute instanceof MultiPolygon) {
                    return ((MultiPolygon) attribute).toText();// 返回 WKT
                }

                // 如果是Polygon 则 -> MultiPolygon -> WKT 返回
                if (attribute instanceof Polygon) {
                    GeometryFactory geometryFactory = JTSFactoryFinder.getGeometryFactory();
                    Polygon[] polygons = {(Polygon) attribute};
                    MultiPolygon multiPolygon = geometryFactory.createMultiPolygon(polygons);
                    return multiPolygon.toText();
                }
            }
            throw new MultiPolygonException("no geometry field in record");
        }
    }
}
