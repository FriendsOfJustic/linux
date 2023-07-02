package com.example.geohazardmain.Service;


import org.postgresql.util.PSQLException;

import java.io.IOException;

public interface GeohazardChainService {


    public void PollingLogic() throws IOException, PSQLException;
}