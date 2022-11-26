package stanbot;

import org.openapitools.client.*;

import org.openapitools.client.model.*;
import org.openapitools.client.api.*;

public class StanBot {

    public static void main(String[] args) {
        System.out.println("StanBot start");
        InvestorApi client = new InvestorApi();

        RegisterInvestorDto registerInvestorDto = new RegisterInvestorDto();
        registerInvestorDto.setName("StanBot");

        try {
            ApiResponse<InvestorDto> investor = client.registerBotWithHttpInfo(registerInvestorDto);
        } catch(ApiException e) {
            System.out.println(e);
        }
        return;
    }
}