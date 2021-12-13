`timescale 1ns / 1ps
`include "define.vh"


module multiplxer2(reg_we,is_load,is_store,is_halt,rs2_data,r_data,data_memory,w_data_memo,alu_result);



input reg_we,is_load,is_store,is_halt;
input [31:0] data_memory,rs2_data,alu_result;



output reg[31:0]r_data,w_data_memo;



always @(*)begin
    if(is_load)begin
      r_data=data_memory;
      w_data_memo=32'd0;
    end else if(is_store) begin
      r_data=alu_result;
      w_data_memo=rs2_data;
    end else begin
      r_data=alu_result;
      
      
    end


  
end



endmodule