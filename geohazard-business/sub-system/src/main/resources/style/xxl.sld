<?xml version="1.0" encoding="UTF-8"?>
<StyledLayerDescriptor xmlns="http://www.opengis.net/sld" version="1.0.0" xmlns:sld="http://www.opengis.net/sld" xmlns:ogc="http://www.opengis.net/ogc" xmlns:gml="http://www.opengis.net/gml">
  <UserLayer>
    <sld:LayerFeatureConstraints>
      <sld:FeatureTypeConstraint/>
    </sld:LayerFeatureConstraints>
    <sld:UserStyle>
      <sld:Name>slope_xxl_2_9</sld:Name>
      <sld:FeatureTypeStyle>
        <sld:Rule>
          <sld:RasterSymbolizer>
            <sld:ChannelSelection>
              <sld:GrayChannel>
                <sld:SourceChannelName>1</sld:SourceChannelName>
              </sld:GrayChannel>
            </sld:ChannelSelection>
            <sld:ColorMap type="ramp">
              <sld:ColorMapEntry quantity="-0.61306101083755493" label="-0.6131" color="#d7191c"/>
              <sld:ColorMapEntry quantity="-0.43763725832104683" label="-0.4376" color="#fdae61"/>
              <sld:ColorMapEntry quantity="-0.26221350580453873" label="-0.2622" color="#ffffbf"/>
              <sld:ColorMapEntry quantity="-0.086789753288030624" label="-0.0868" color="#abdda4"/>
              <sld:ColorMapEntry quantity="0.088633999228477478" label="0.0886" color="#2b83ba"/>
            </sld:ColorMap>
          </sld:RasterSymbolizer>
        </sld:Rule>
      </sld:FeatureTypeStyle>
    </sld:UserStyle>
  </UserLayer>
</StyledLayerDescriptor>
