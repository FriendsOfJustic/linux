package com.rsgisai.geohazard.level.service;

import com.rsgisai.geohazard.level.exception.SusceptibilityAlgorithmException;

import java.io.IOException;

/**
 * @author tfh, created at 2023-02-14 10:38 AM
 */
public interface AlgorithmService {
    void calculateDerived(Long workingAreaId, String feature);

    void calculateAllDerived(Long workingAreaId);

    void reclassify(long workingAreaId, String feature, int n) throws SusceptibilityAlgorithmException;

    int generateXxlInRaster(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException;

    int curvatureXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException;

    int slopeXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException;

    int aspectXxlRasterGenerate(long workingAreaId, int numberClasses) throws SusceptibilityAlgorithmException, IOException;

    String generateReclassexpr(int n, double min, double max);



    void calculateEvaluation(long workingAreaId, Integer demNumberClasses, Integer slopeNumberClasses, Integer aspectNumberClasses, Integer curvatureNumberClasses, Integer outNumClass) throws SusceptibilityAlgorithmException, IOException;
}
