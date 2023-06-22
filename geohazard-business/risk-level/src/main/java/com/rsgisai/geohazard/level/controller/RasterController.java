package com.rsgisai.geohazard.level.controller;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.rsgisai.geohazard.level.entity.EvaluationRasterRecord;
import com.rsgisai.geohazard.system.common.entity.RasterRecord;
import com.rsgisai.geohazard.entity.WorkingArea;
import com.rsgisai.geohazard.level.dao.pgsql.*;
import com.rsgisai.geohazard.level.entity.RasterDaoParam;
import com.rsgisai.geohazard.level.entity.XxlRasterRecord;
import com.rsgisai.geohazard.level.service.RasterService;
import com.rsgisai.geohazard.level.vo.RasterQueryVo;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.util.*;

/**
 * @author tfh, created at 2023-02-18 10:12 AM
 */
@RestController
@RequestMapping("/raster")
public class RasterController {
    @Autowired
    ObjectMapper objectMapper;
    @Autowired
    private RasterService rasterService;
    @Autowired
    private EvaluationAlgorithmDao evaluationAlgorithmDao;
    @Autowired
    private XxlAlgorithmDao xxlAlgorithmDao;

    @Autowired
    private WorkingAreaDao workingAreaDao;
    @Autowired
    private RasterDao rasterDao;

    @GetMapping()
    public R<Object> list(HttpServletRequest request) {
        String url = request.getRequestURL().toString();
        System.out.println("Request URL: " + url);
        if (url.charAt(url.length() - 1) == '/') url = url.substring(0, url.length() - 1);
        String finalUrl = url;
        List<Map<String, String>> list = new ArrayList<>();
        List<WorkingArea> workingAreaList = workingAreaDao.select(new WorkingArea());
        for (WorkingArea workingArea : workingAreaList) {
            list.add(new HashMap<String, String>() {{
                put("url", finalUrl + "/workingArea/" + workingArea.getId());
                put("name", workingArea.getName());
            }});
        }
        return R.success(list);
    }

    @GetMapping("/workingArea/{workingAreaId}")
    public R<Object> workingAreaRasterList(HttpServletRequest request,
                                           @PathVariable("workingAreaId") Long workingAreaId) {
        String url = request.getRequestURL().toString();
        System.out.println("Request URL: " + url);
        Map<String, Object> map = new LinkedHashMap<>();

        Map<String, Object> step0 = new LinkedHashMap<>();
        for (String raster : new String[]{"dem"}) {
            RasterDaoParam rasterDaoParam = new RasterDaoParam(raster, workingAreaId, null);
            rasterDaoParam.setTable(raster);
            rasterDaoParam.setWorkingAreaId(workingAreaId);
            List<RasterRecord> select = rasterDao.select(rasterDaoParam);
            for (RasterRecord rasterRecord : select) {
                step0.put(raster + "#" + rasterRecord.getId(), url + "/feature/" + raster);
            }
        }
        map.put("original", step0);

        Map<String, Object> step1 = new LinkedHashMap<>();
        for (String raster : new String[]{"slope", "aspect", "curvature"}) {
            RasterDaoParam rasterDaoParam = new RasterDaoParam(raster, workingAreaId, null);
            rasterDaoParam.setTable(raster);
            rasterDaoParam.setWorkingAreaId(workingAreaId);
            List<RasterRecord> select = rasterDao.select(rasterDaoParam);
            for (RasterRecord rasterRecord : select) {
                step1.put(raster + "#" + rasterRecord.getId(), url + "/feature/" + raster);
            }
        }
        map.put("step1", step1);


        Map<String, Object> step2 = new LinkedHashMap<>();
        for (String raster : new String[]{
                "dem_reclassify",
                "slope_reclassify",
                "aspect_reclassify",
                "curvature_reclassify",
        }) {
            RasterDaoParam rasterDaoParam = new RasterDaoParam(raster, workingAreaId, null);
            rasterDaoParam.setTable(raster);
            rasterDaoParam.setWorkingAreaId(workingAreaId);
            List<RasterRecord> select = rasterDao.selectNumClasses(rasterDaoParam);
            for (RasterRecord rasterRecord : select) {
                step2.put(raster + "#" + rasterRecord.getId(), url + "/feature/" + raster + "/numberClasses/" + rasterRecord.getNumberClasses());
            }
        }
        map.put("step2", step2);

        Map<String, Object> step3 = new LinkedHashMap<>();
        for (String raster : new String[]{
                "dem_xxl",
                "slope_xxl",
                "aspect_xxl",
                "curvature_xxl",
        }) {
            RasterDaoParam rasterDaoParam = new RasterDaoParam(raster, workingAreaId, null);
            rasterDaoParam.setTable(raster);
            rasterDaoParam.setWorkingAreaId(workingAreaId);
            List<RasterRecord> select = rasterDao.selectNumClasses(rasterDaoParam);
            for (RasterRecord rasterRecord : select) {
                step3.put(raster + "#" + rasterRecord.getId(), url + "/feature/" + raster + "/numberClasses/" + rasterRecord.getNumberClasses());
            }
        }
        map.put("step3", step3);

        Map<Object, Object> step4 = new LinkedHashMap<>();
        for (String raster : new String[]{"information_amount_all"}) {
            XxlRasterRecord xxlRasterRecord = new XxlRasterRecord();
            xxlRasterRecord.setWorkingAreaId(workingAreaId);
            List<XxlRasterRecord> select = xxlAlgorithmDao.select(xxlRasterRecord);
            for (XxlRasterRecord record : select) {
                step4.put(raster + "#" + record.id, url + "/feature/" + raster
                        + "/demNumberClasses/" + record.demNumberClasses
                        + "/slopeNumberClasses/" + record.slopeNumberClasses
                        + "/aspectNumberClasses/" + record.aspectNumberClasses
                        + "/curvatureNumberClasses/" + record.curvatureNumberClasses
                );
            }
        }
        map.put("step4", step4);

        Map<Object, Object> step5 = new LinkedHashMap<>();
        for (String raster : new String[]{"evaluation"}) {
            EvaluationRasterRecord evaluationRasterRecord = new EvaluationRasterRecord();
            evaluationRasterRecord.setWorkingAreaId(workingAreaId);
            List<EvaluationRasterRecord> select = evaluationAlgorithmDao.select(evaluationRasterRecord);
            for (EvaluationRasterRecord record : select) {
                step5.put(raster + "#" + record.id, url + "/feature/" + raster
                        + "/outNumberClasses/" + record.outNumberClasses
                        + "/demNumberClasses/" + record.demNumberClasses
                        + "/slopeNumberClasses/" + record.slopeNumberClasses
                        + "/aspectNumberClasses/" + record.aspectNumberClasses
                        + "/curvatureNumberClasses/" + record.curvatureNumberClasses
                );
            }
        }
        map.put("step5", step5);
        return R.success(map);
    }

    @GetMapping("/workingArea/{workingAreaId}/feature/information_amount_all"
            + "/demNumberClasses/{demNumberClasses}"
            + "/slopeNumberClasses/{slopeNumberClasses}"
            + "/aspectNumberClasses/{aspectNumberClasses}"
            + "/curvatureNumberClasses/{curvatureNumberClasses}"
    )
    public ResponseEntity<byte[]> xxlDownload(
            @PathVariable("workingAreaId") Long workingAreaId,
            @PathVariable("demNumberClasses") Integer demNumberClasses,
            @PathVariable("slopeNumberClasses") Integer slopeNumberClasses,
            @PathVariable("aspectNumberClasses") Integer aspectNumberClasses,
            @PathVariable("curvatureNumberClasses") Integer curvatureNumberClasses
    ) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.setFormat("geotiff");
        rasterQueryVo.setFeature("information_amount_all");
        rasterQueryVo.workingAreaId = workingAreaId;
        rasterQueryVo.demNumberClasses = demNumberClasses;
        rasterQueryVo.slopeNumberClasses = slopeNumberClasses;
        rasterQueryVo.aspectNumberClasses = aspectNumberClasses;
        rasterQueryVo.curvatureNumberClasses = curvatureNumberClasses;
        return download(rasterQueryVo);
    }
    @GetMapping("/workingArea/{workingAreaId}/feature/evaluation"
            + "/outNumberClasses/{outNumberClasses}"
            + "/demNumberClasses/{demNumberClasses}"
            + "/slopeNumberClasses/{slopeNumberClasses}"
            + "/aspectNumberClasses/{aspectNumberClasses}"
            + "/curvatureNumberClasses/{curvatureNumberClasses}"
    )
    public ResponseEntity<byte[]> evaluationDownload(
            @PathVariable("workingAreaId") Long workingAreaId,
            @PathVariable("outNumberClasses") Integer outNumberClasses,
            @PathVariable("demNumberClasses") Integer demNumberClasses,
            @PathVariable("slopeNumberClasses") Integer slopeNumberClasses,
            @PathVariable("aspectNumberClasses") Integer aspectNumberClasses,
            @PathVariable("curvatureNumberClasses") Integer curvatureNumberClasses
    ) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.setFormat("geotiff");
        rasterQueryVo.setFeature("evaluation");
        rasterQueryVo.workingAreaId = workingAreaId;
        rasterQueryVo.outNumberClasses = outNumberClasses;
        rasterQueryVo.demNumberClasses = demNumberClasses;
        rasterQueryVo.slopeNumberClasses = slopeNumberClasses;
        rasterQueryVo.aspectNumberClasses = aspectNumberClasses;
        rasterQueryVo.curvatureNumberClasses = curvatureNumberClasses;
        return download(rasterQueryVo);
    }

    @GetMapping("/workingArea/{workingAreaId}/feature/{feature}/numberClasses/{numberClasses}")
    public ResponseEntity<byte[]> evaluation(
            @PathVariable("workingAreaId") Long workingAreaId,
            @PathVariable("feature") String feature,
            @PathVariable("numberClasses") Integer numberClasses
    ) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.setFormat("geotiff");
        rasterQueryVo.setWorkingAreaId(workingAreaId);
        rasterQueryVo.setFeature(feature);
        rasterQueryVo.setNumberClasses(numberClasses);
        return download(rasterQueryVo);
    }

    @GetMapping("/workingArea/{workingAreaId}/feature/{feature}")
    public ResponseEntity<byte[]> evaluation(
            @PathVariable("workingAreaId") Long workingAreaId,
            @PathVariable("feature") String feature
    ) throws IOException {
        RasterQueryVo rasterQueryVo = new RasterQueryVo();
        rasterQueryVo.setFormat("geotiff");
        rasterQueryVo.setWorkingAreaId(workingAreaId);
        rasterQueryVo.setFeature(feature);
        return download(rasterQueryVo);
    }


    public ResponseEntity<byte[]> download(RasterQueryVo rasterQueryVo) throws IOException {
        if (rasterQueryVo.getFormat() == null) {
            byte[] bytes = objectMapper.writeValueAsBytes(R.fail("please specify a 'format' parameter, currently supported format is 'geotiff'"));
            return ResponseEntity.ok().contentType(MediaType.APPLICATION_JSON).body(bytes);
        }
        if (!"geotiff".equalsIgnoreCase(rasterQueryVo.getFormat())) {
            byte[] bytes = objectMapper.writeValueAsBytes(R.fail("supported format: geotiff"));
            return ResponseEntity.ok().contentType(MediaType.APPLICATION_JSON).body(bytes);
        }
        byte[] bytea;
        String feature = rasterQueryVo.getFeature();
        String DELIMITER = "_";
        String filename;
        switch (feature) {
            case "dem":
            case "slope":
            case "aspect":
            case "curvature":
                filename = rasterQueryVo.getFeature()
                        + DELIMITER + rasterQueryVo.getWorkingAreaId()
                        + ".tif";
                bytea = rasterService.getRasterInputStream(rasterQueryVo);
                break;
            case "dem_reclassify":
            case "slope_reclassify":
            case "aspect_reclassify":
            case "curvature_reclassify":

            case "dem_xxl":
            case "slope_xxl":
            case "aspect_xxl":
            case "curvature_xxl":
                filename = rasterQueryVo.getFeature()
                        + DELIMITER + rasterQueryVo.getWorkingAreaId()
                        + DELIMITER + rasterQueryVo.getNumberClasses()
                        + ".tif";
                bytea = rasterService.getRasterInputStream(rasterQueryVo);
                break;
            case "information_amount_all":
                filename = rasterQueryVo.getFeature()
                        + DELIMITER + rasterQueryVo.getWorkingAreaId()
                        + DELIMITER + rasterQueryVo.getDemNumberClasses()
                        + DELIMITER + rasterQueryVo.getSlopeNumberClasses()
                        + DELIMITER + rasterQueryVo.getAspectNumberClasses()
                        + DELIMITER + rasterQueryVo.getCurvatureNumberClasses()
                        + ".tif";
                bytea = rasterService.getXxlAllInputStream(rasterQueryVo);
                break;
            case "evaluation":
                filename = rasterQueryVo.getFeature()
                        + DELIMITER + rasterQueryVo.getWorkingAreaId()
                        + DELIMITER + rasterQueryVo.getOutNumberClasses()
                        + DELIMITER + rasterQueryVo.getDemNumberClasses()
                        + DELIMITER + rasterQueryVo.getSlopeNumberClasses()
                        + DELIMITER + rasterQueryVo.getAspectNumberClasses()
                        + DELIMITER + rasterQueryVo.getCurvatureNumberClasses()
                        + ".tif";
                bytea = rasterService.getEvaluationInputStream(rasterQueryVo);
                break;
            default:
                throw new RuntimeException("not supported feature.");
        }

        return ResponseEntity.ok()
                .contentLength(bytea.length)
                .contentType(MediaType.APPLICATION_OCTET_STREAM)
                .header(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename=" + filename)
                .body(bytea);
    }
}
