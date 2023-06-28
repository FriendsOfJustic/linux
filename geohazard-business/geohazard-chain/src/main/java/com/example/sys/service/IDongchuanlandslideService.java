package com.example.sys.service;

import com.example.sys.entity.Dongchuanlandslide;
import com.baomidou.mybatisplus.extension.service.IService;
import com.example.sys.transfer.BlockRiver;
import com.example.sys.vo.DongchuanSlideResponse;

import java.io.IOException;
import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author sht
 * @since 2023-04-17
 */
public interface IDongchuanlandslideService {


    //public DongchuanSlideResponse BlockRiverAlgorithm(String number, Double waterWidth, Double waterDepth, Double l1);


    public String BlockRiverAlgorithm(List<BlockRiver> para) throws IOException;

    public void deleteAllMidResult(Integer num);
}
