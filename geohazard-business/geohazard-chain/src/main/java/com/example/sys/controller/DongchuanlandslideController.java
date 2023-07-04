package com.example.sys.controller;
import com.example.sys.geoserver.GeoserverRestManager;
import com.example.sys.mapper.DongchuanlandslideMapper;
import com.example.sys.service.IDongchuanlandslideService;
import com.example.sys.transfer.BlockRiver;
import com.rsgisai.geohazard.system.common.R;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author sht
 * @since 2023-04-17
 */
@RestController
@RequestMapping("/sys")
public class DongchuanlandslideController {


    @Autowired
    private IDongchuanlandslideService iDongchuanlandslideService;



    @Autowired
    private DongchuanlandslideMapper dongchuanlandslideMapper;

    //public boolean BlockRiverAlgorithm(String number,Double waterWidth,Double waterDepth,Double l1);
//    @PostMapping ("/Algorithm")
//    public R<DongchuanSlideResponse> fun(@RequestBody ParamData paramData)
//    {
////        System.out.println(paramData.toString());
////        if(paramData==null)
////            return R.fail(null, "空参数");
////        //DongchuanSlideResponse ret=iDongchuanlandslideService.BlockRiverAlgorithm(paramData.getDhwxx_number(),paramData.getDhwxx_with(),paramData.getDhwxx_depth(),paramData.getDhwxx_l1());
////
//        DongchuanSlideResponse ret=new DongchuanSlideResponse(1,1,1,1,1,true);
//        //System.out.println(dongchuanlandslideMapper.test("dongchuanlandslide","gid"));
//        return R.ok(ret);
//        //iDongchuanlandslideService.BlockRiverAlgorithm();
//
//    }


    @PostMapping ("/Algorithm")
    public R<String> fun(@RequestBody List<BlockRiver> para) throws IOException {
        List<BlockRiver> test_para=new ArrayList<>();
        for (BlockRiver e:para
        ) {
            System.out.println(e.toString());
        }
//        test_para.add(new BlockRiver("53011301105R",1274.5243,4.5322,41.0,1.1296,29.866,2.965569869));
//        test_para.add(new BlockRiver("53011301060R",633.9669,2.76374,110.52810,2.62069,27.52754,0.5682504736));
//        test_para.add(new BlockRiver("53011301040R",1274.5243,4.5322,41.0,1.1296,29.866,2.965));
//        test_para.add(new BlockRiver("53011301018R",1274.5243,4.5322,41.0,1.1296,29.866,2.965));
//        test_para.add(new BlockRiver("53011301071R",473.0,3.58,46.0,1.8985,37.3696,0.856233));
        iDongchuanlandslideService.BlockRiverAlgorithm(para);
        return R.ok("blockriverriskpoint");
    }


    @Autowired
    private GeoserverRestManager geoserverManager;
    @GetMapping ("/test")
    public void fun() throws IOException {

//        Boolean ret=geoserverManager.DeleteLayer("geohazard","BlockRiver");
        Boolean ret = geoserverManager.DeleteDataStores("geohazard", "BlockRiver");
//        ret= ret;

       if(ret==true)
           System.out.println("删除成功");
       else
           System.out.println("删除失败");
    }

}
