<?xml version="1.0" encoding="UTF-8"?>
<StyledLayerDescriptor xmlns="http://www.opengis.net/sld" version="1.0.0" xmlns:sld="http://www.opengis.net/sld" xmlns:ogc="http://www.opengis.net/ogc" xmlns:gml="http://www.opengis.net/gml">
  <UserLayer>
    <sld:LayerFeatureConstraints>
      <sld:FeatureTypeConstraint/>
    </sld:LayerFeatureConstraints>
    <sld:UserStyle>
      <sld:Name>dem_reclassify_9</sld:Name>
      <sld:FeatureTypeStyle>
        <sld:Rule>
          <sld:RasterSymbolizer>
            <sld:ChannelSelection>
              <sld:GrayChannel>
                <sld:SourceChannelName>1</sld:SourceChannelName>
              </sld:GrayChannel>
            </sld:ChannelSelection>
            <sld:ColorMap type="values">
              <sld:ColorMapEntry quantity="0" label="" color="#aeefd5" opacity="0"/>
              <sld:ColorMapEntry quantity="1" label="1" color="#aeefd5"/>
              <sld:ColorMapEntry quantity="2" label="2" color="#f9fcb2"/>
              <sld:ColorMapEntry quantity="3" label="3" color="#15972f"/>
              <sld:ColorMapEntry quantity="4" label="4" color="#a9a726"/>
              <sld:ColorMapEntry quantity="5" label="5" color="#c04a02"/>
              <sld:ColorMapEntry quantity="6" label="6" color="#741604"/>
              <sld:ColorMapEntry quantity="7" label="7" color="#75401e"/>
              <sld:ColorMapEntry quantity="8" label="8" color="#aba8a6"/>
              <sld:ColorMapEntry quantity="9" label="9" color="#ebe9eb"/>
            </sld:ColorMap>
          </sld:RasterSymbolizer>
        </sld:Rule>
      </sld:FeatureTypeStyle>
    </sld:UserStyle>
  </UserLayer>
</StyledLayerDescriptor>
