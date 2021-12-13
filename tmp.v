`timescale 1ns / 1ps
`include "define.vh"

module tmp(clk, we,is_load,is_store,r_addr,w_addr,
);
input clk,is_load,is_store;
input [3:0]we;

input [4:0] r_addr,w_addr;
input [31:0] w_data;
output reg[31:0] r_data;
reg [31:0]mem[0:31];

always @(posegde clk)begin


     case(opcode)
     `ALU_LB:begin
      if(store_load_addr%4==0)begin
        r_data<={24{mem[r_addr][31]},mem[r_addr][31:24]};
      end else if(store_load_addr%4==1)begin
        r_data<={24{mem[r_addr][23]},mem[r_addr][23:16]};
      end else if(store_load_addr%4==2)begin
          r_data<={24{mem[r_addr][15]},mem[r_addr][15:8]};
      end else begin
         r_data<={24{mem[r_addr][7]},mem[r_addr][7:0]};
      end
      
  end
  `ALU_LBU:begin
    if(store_load_addr%4==0)begin
        r_data<={24{0},mem[r_addr][31:24]};
      end else if(store_load_addr%4==1)begin
        r_data<={24{0},mem[r_addr][23:16]};
      end else if(store_load_addr%4==2)begin
          r_data<={24{0},mem[r_addr][15:8]};
      end else begin
         r_data<={24{0},mem[r_addr][7:0]};
      end
  end
  `ALU_LH:begin
     if(store_load_addr%4==0)begin
        r_data<={16{mem[r_addr][23]},mem[r_addr][23:16],mem[r_addr][31:24]};
      end else if(store_load_addr%4==1)begin
        r_data<={16{mem[r_addr][15]},mem[r_addr][15:8],mem[r_addr][23:16]};
      end else if(store_load_addr%4==2)begin
          r_data<={16{mem[r_addr][7]},mem[r_addr][7:0],mem[r_addr][15:8]};
      end
  end
  `ALU_LHU:begin
     if(store_load_addr%4==0)begin
        r_data<={16{0},mem[r_addr][23:16],mem[r_addr][31:24]};
      end else if(store_load_addr%4==1)begin
        r_data<={16{0},mem[r_addr][15:8],mem[r_addr][23:16]};
      end else if(store_load_addr%4==2)begin
          r_data<={16{0},mem[r_addr][7:0],mem[r_addr][15:8]};
      end
  end
  `ALU_LW:begin
     r_data<={mem[r_addr][7:0],mem[r_addr][15:8],mem[r_addr][23:16],mem[r_addr][31:24]};
  end
  default:r_data<=0;

    endcase


   if(we[0])mem[w_addr][7:0]<=w_data[7:0];
   if(we[1])mem[w_addr][15:0]<=w_data[15:0];
   if(we[2])mem[w_addr][23:16]<=w_data[23:16];
   if(we[3])mem[w_addr][31:24]<=w_data[31:24];
   r_data<=mem[r_addr];

  
end

endmodule 