package com.rsgisai.util.math;

import org.apache.poi.ss.usermodel.*;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class XLSParser {

    public List<Map<String, Double>> parseXLS(String filePath) throws IOException {
        try (FileInputStream fis = new FileInputStream(filePath);
             Workbook workbook = WorkbookFactory.create(fis)) {

            Sheet sheet = workbook.getSheetAt(0); // 获取第一个工作表

            // 获取表头行
            Row headerRow = sheet.getRow(0);

            // 迭代表头单元格并打印
            for (Cell cell : headerRow) {
                String cellValue = cell.getStringCellValue();
//                System.out.print(cellValue + "\t");
            }
//            System.out.println();

            ArrayList<Map<String, Double>> result = new ArrayList<>();

            // 获取数据行数
            int rowCount = sheet.getLastRowNum();

            // 迭代数据行并打印每个单元格的值
            for (int i = 1; i <= rowCount; i++) {
                Row row = sheet.getRow(i);
                HashMap<String, Double> map = new HashMap<>();
                int j = 0;
                for (Cell cell : row) {
                    String cellValue = "";
                    if (cell.getCellType() == CellType.STRING) {
                        cellValue = cell.getStringCellValue();
                    } else if (cell.getCellType() == CellType.NUMERIC) {
                        cellValue = String.valueOf(cell.getNumericCellValue());
                    }
                    map.put(headerRow.getCell(j).getStringCellValue(), cell.getNumericCellValue());
//                    System.out.print(cellValue + "\t");
                    j++;
                }
                result.add(map);
//                System.out.println();
            }
            return result;
        }
    }

    public static void main(String[] args) {
        try {
            String filePath = "path/to/your/file.xls";
            XLSParser parser = new XLSParser();
            parser.parseXLS(filePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void addColumn(String path, List<Double> predictions) {
        try (FileInputStream fis = new FileInputStream(path);
             Workbook workbook = WorkbookFactory.create(fis)) {

            Sheet sheet = workbook.getSheetAt(0); // Get the first sheet

            // Shift existing columns to the right
//            int lastRowNum = sheet.getLastRowNum();
//            for (int i = lastRowNum; i >= 0; i--) {
//                Row row = sheet.getRow(i);
//                Cell newCell = row.createCell(row.getLastCellNum());
//                Cell oldCell = row.getCell(row.getLastCellNum() - 1);
//                if (oldCell != null) {
//                    CellValue cellValue = evaluateCell(oldCell, workbook.getCreationHelper());
//                    setCellValue(newCell, cellValue);
//                }
//            }

            // Update header value in the new column
            Row headerRow = sheet.getRow(0);
            Cell newHeaderCell = headerRow.createCell(headerRow.getLastCellNum());
            newHeaderCell.setCellValue("Predictions");

            // Update column data in the new column
            for (int i = 0; i < predictions.size(); i++) {
                Row dataRow = sheet.getRow(i + 1);
                Cell newDataCell = dataRow.createCell(dataRow.getLastCellNum());
                newDataCell.setCellValue(predictions.get(i));
            }

            // Write the changes back to the file
            try (FileOutputStream fos = new FileOutputStream(path)) {
                workbook.write(fos);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
