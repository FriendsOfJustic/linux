package com.rsgisai.util.gis.util.geoserver.exception.style;

import com.rsgisai.util.gis.util.geoserver.exception.GeoserverException;

/**
 * @author tfh, created at 2023-04-13 9:06 PM
 */
public class StyleNotFoundException extends GeoserverException {
    public StyleNotFoundException(String workspace, String styleName) {
        super("style(" + workspace + ":" + styleName + ") not found!");
    }
}
