WASM_OPCODE("unreachable", void, void, special, agnostic, 0x00)
WASM_OPCODE("nop", void, void, special, agnostic, 0x01)
WASM_OPCODE("block", void, void, typed, agnostic, 0x02)
WASM_OPCODE("loop", void, void, typed, agnostic, 0x03)
WASM_OPCODE("if", void, void, typed, agnostic, 0x04)
WASM_OPCODE("else", void, void, special, agnostic, 0x05)
WASM_OPCODE("**br", void, void, fakebreak, agnostic, 0x06)
WASM_OPCODE("end", void, void, special, agnostic, 0x0b)
WASM_OPCODE("br", void, void, break, agnostic, 0x0c)
WASM_OPCODE("br_if", void, void, break_if, agnostic, 0x0d)
WASM_OPCODE("br_table", void, void, break_table, agnostic, 0x0e)
WASM_OPCODE("return", void, void, return, agnostic, 0x0f)

WASM_OPCODE("call", any, any, call, agnostic, 0x10)
WASM_OPCODE("call_indirect", any, any, call_indirect, agnostic, 0x11)

WASM_OPCODE("drop", any, any, drop, agnostic, 0x1a)
WASM_OPCODE("select", any, any, select, agnostic, 0x1b)

WASM_OPCODE("get_local", any, any, get_local, agnostic, 0x20)
WASM_OPCODE("set_local", any, any, set_local, agnostic, 0x21)
WASM_OPCODE("tee_local", any, any, tee_local, agnostic, 0x22)
WASM_OPCODE("get_global", any, any, get_local, agnostic, 0x23)
WASM_OPCODE("set_global", any, any, set_local, agnostic, 0x24)

WASM_OPCODE("i32.load", i32, i32, load, agnostic, 0x28)
WASM_OPCODE("i64.load", i32, i64, load, agnostic, 0x29)
WASM_OPCODE("f32.load", i32, f32, load, agnostic, 0x2a)
WASM_OPCODE("f64.load", i32, f64, load, agnostic, 0x2b)
WASM_OPCODE("i32.load8_s", i32, i32, load, signed, 0x2c)
WASM_OPCODE("i32.load8_u", i32, i32, load, unsigned, 0x2d)
WASM_OPCODE("i32.load16_s", i32, i32, load, signed, 0x2e)
WASM_OPCODE("i32.load16_u", i32, i32, load, unsigned, 0x2f)
WASM_OPCODE("i64.load8_s", i32, i64, load, signed, 0x30)
WASM_OPCODE("i64.load8_u", i32, i64, load, unsigned, 0x31)
WASM_OPCODE("i64.load16_s", i32, i64, load, signed, 0x32)
WASM_OPCODE("i64.load16_u", i32, i64, load, unsigned, 0x33)
WASM_OPCODE("i64.load32_s", i32, i64, load, signed, 0x34)
WASM_OPCODE("i64.load32_u", i32, i64, load, unsigned, 0x35)
WASM_OPCODE("i32.store", i32, void, store, agnostic, 0x36)
WASM_OPCODE("i64.store", i64, void, store, agnostic, 0x37)
WASM_OPCODE("f32.store", f32, void, store, agnostic, 0x38)
WASM_OPCODE("f64.store", f64, void, store, agnostic, 0x39)
WASM_OPCODE("i32.store8", i32, void, store, agnostic, 0x3a)
WASM_OPCODE("i32.store16", i32, void, store, agnostic, 0x3b)
WASM_OPCODE("i64.store8", i64, void, store, agnostic, 0x3c)
WASM_OPCODE("i64.store16", i64, void, store, agnostic, 0x3d)
WASM_OPCODE("i64.store32", i64, void, store, agnostic, 0x3e)

WASM_OPCODE("i32.const", i32, i32, constant_i32, agnostic, 0x41)
WASM_OPCODE("i64.const", i64, i64, constant_i64, agnostic, 0x42)
WASM_OPCODE("f32.const", f32, f32, constant_f32, agnostic, 0x43)
WASM_OPCODE("f64.const", f64, f64, constant_f64, agnostic, 0x44)

WASM_OPCODE("i32.eqz", i32, i32, eqz, agnostic,    0x45)
WASM_OPCODE("i32.eq", i32, i32, relational, agnostic, 0x46)
WASM_OPCODE("i32.ne", i32, i32, relational, agnostic, 0x47)
WASM_OPCODE("i32.lt_s", i32, i32, relational, signed,   0x48)
WASM_OPCODE("i32.lt_u", i32, i32, relational, unsigned, 0x49)
WASM_OPCODE("i32.gt_s", i32, i32, relational, signed,   0x4a)
WASM_OPCODE("i32.gt_u", i32, i32, relational, unsigned, 0x4b)
WASM_OPCODE("i32.le_s", i32, i32, relational, signed,   0x4c)
WASM_OPCODE("i32.le_u", i32, i32, relational, unsigned, 0x4d)
WASM_OPCODE("i32.ge_s", i32, i32, relational, signed,   0x4e)
WASM_OPCODE("i32.ge_u", i32, i32, relational, unsigned, 0x4f)

WASM_OPCODE("i64.eqz", i64, i32, eqz, agnostic,    0x50)
WASM_OPCODE("i64.eq", i64, i32, relational, agnostic, 0x51)
WASM_OPCODE("i64.ne", i64, i32, relational, agnostic, 0x52)
WASM_OPCODE("i64.lt_s", i64, i32, relational, signed,   0x53)
WASM_OPCODE("i64.lt_u", i64, i32, relational, unsigned, 0x54)
WASM_OPCODE("i64.gt_s", i64, i32, relational, signed,   0x55)
WASM_OPCODE("i64.gt_u", i64, i32, relational, unsigned, 0x56)
WASM_OPCODE("i64.le_s", i64, i32, relational, signed,   0x57)
WASM_OPCODE("i64.le_u", i64, i32, relational, unsigned, 0x58)
WASM_OPCODE("i64.ge_s", i64, i32, relational, signed,   0x59)
WASM_OPCODE("i64.ge_u", i64, i32, relational, unsigned, 0x5a)

WASM_OPCODE("f32.eq", f32, i32, relational, floating, 0x5b)
WASM_OPCODE("f32.ne", f32, i32, relational, floating, 0x5c)
WASM_OPCODE("f32.lt", f32, i32, relational, floating, 0x5d)
WASM_OPCODE("f32.gt", f32, i32, relational, floating, 0x5e)
WASM_OPCODE("f32.le", f32, i32, relational, floating, 0x5f)
WASM_OPCODE("f32.ge", f32, i32, relational, floating, 0x60)

WASM_OPCODE("f64.eq", f64, i32, relational, floating, 0x61)
WASM_OPCODE("f64.ne", f64, i32, relational, floating, 0x62)
WASM_OPCODE("f64.lt", f64, i32, relational, floating, 0x63)
WASM_OPCODE("f64.gt", f64, i32, relational, floating, 0x64)
WASM_OPCODE("f64.le", f64, i32, relational, floating, 0x65)
WASM_OPCODE("f64.ge", f64, i32, relational, floating, 0x66)

WASM_OPCODE("i32.clz", i32, i32, unary, agnostic,    0x67)
WASM_OPCODE("i32.ctz", i32, i32, unary, agnostic,    0x68)
WASM_OPCODE("i32.popcnt", i32, i32, unary, agnostic, 0x69)

WASM_OPCODE("i32.add", i32, i32, binary, agnostic, 0x6a)
WASM_OPCODE("i32.sub", i32, i32, binary, agnostic, 0x6b)
WASM_OPCODE("i32.mul", i32, i32, binary, agnostic, 0x6c)
WASM_OPCODE("i32.div_s", i32, i32, binary, signed,   0x6d)
WASM_OPCODE("i32.div_u", i32, i32, binary, unsigned, 0x6e)
WASM_OPCODE("i32.rem_s", i32, i32, binary, signed,   0x6f)
WASM_OPCODE("i32.rem_u", i32, i32, binary, unsigned, 0x70)
WASM_OPCODE("i32.and", i32, i32, binary, agnostic, 0x71)
WASM_OPCODE("i32.or",  i32, i32, binary, agnostic, 0x72)
WASM_OPCODE("i32.xor", i32, i32, binary, agnostic, 0x73)
WASM_OPCODE("i32.shl", i32, i32, binary, agnostic, 0x74)
WASM_OPCODE("i32.shr_s", i32, i32, binary, signed,   0x75)
WASM_OPCODE("i32.shr_u", i32, i32, binary, unsigned, 0x76)
WASM_OPCODE("i32.rotl", i32, i32, binary, agnostic, 0x77)
WASM_OPCODE("i32.rotr", i32, i32, binary, agnostic, 0x78)

WASM_OPCODE("i64.clz", i64, i64, unary, agnostic,    0x79)
WASM_OPCODE("i64.ctz", i64, i64, unary, agnostic,    0x7a)
WASM_OPCODE("i64.popcnt", i64, i64, unary, agnostic, 0x7b)

WASM_OPCODE("i64.add", i64, i64, binary, agnostic, 0x7c)
WASM_OPCODE("i64.sub", i64, i64, binary, agnostic, 0x7d)
WASM_OPCODE("i64.mul", i64, i64, binary, agnostic, 0x7e)
WASM_OPCODE("i64.div_s", i64, i64, binary, signed,   0x7f)
WASM_OPCODE("i64.div_u", i64, i64, binary, unsigned, 0x80)
WASM_OPCODE("i64.rem_s", i64, i64, binary, signed,   0x81)
WASM_OPCODE("i64.rem_u", i64, i64, binary, unsigned, 0x82)
WASM_OPCODE("i64.and", i64, i64, binary, agnostic, 0x83)
WASM_OPCODE("i64.or",  i64, i64, binary, agnostic, 0x84)
WASM_OPCODE("i64.xor", i64, i64, binary, agnostic, 0x85)
WASM_OPCODE("i64.shl", i64, i64, binary, agnostic, 0x86)
WASM_OPCODE("i64.shr_s", i64, i64, binary, signed,   0x87)
WASM_OPCODE("i64.shr_u", i64, i64, binary, unsigned, 0x88)
WASM_OPCODE("i64.rotl", i64, i64, binary, agnostic, 0x89)
WASM_OPCODE("i64.rotr", i64, i64, binary, agnostic, 0x8a)

WASM_OPCODE("f32.abs", f32, f32,  unary, floating, 0x8b)
WASM_OPCODE("f32.neg", f32, f32,  unary, floating, 0x8c)
WASM_OPCODE("f32.ceil", f32, f32,  unary, floating, 0x8d)
WASM_OPCODE("f32.floor", f32, f32,  unary, floating, 0x8e)
WASM_OPCODE("f32.trunc", f32, f32,  unary, floating, 0x8f)
WASM_OPCODE("f32.nearest", f32, f32,  unary, floating, 0x90)
WASM_OPCODE("f32.sqrt", f32, f32,  unary, floating, 0x91)
WASM_OPCODE("f32.add", f32, f32, binary, floating, 0x92)
WASM_OPCODE("f32.sub", f32, f32, binary, floating, 0x93)
WASM_OPCODE("f32.mul", f32, f32, binary, floating, 0x94)
WASM_OPCODE("f32.div", f32, f32, binary, floating, 0x95)
WASM_OPCODE("f32.min", f32, f32, binary, floating, 0x96)
WASM_OPCODE("f32.max", f32, f32, binary, floating, 0x97)
WASM_OPCODE("f32.copysign", f32, f32, binary, floating, 0x98)

WASM_OPCODE("f64.abs", f64, f64,  unary, floating, 0x99)
WASM_OPCODE("f64.neg", f64, f64,  unary, floating, 0x9a)
WASM_OPCODE("f64.ceil", f64, f64,  unary, floating, 0x9b)
WASM_OPCODE("f64.floor", f64, f64,  unary, floating, 0x9c)
WASM_OPCODE("f64.trunc", f64, f64,  unary, floating, 0x9d)
WASM_OPCODE("f64.nearest", f64, f64,  unary, floating, 0x9e)
WASM_OPCODE("f64.sqrt", f64, f64,  unary, floating, 0x9f)
WASM_OPCODE("f64.add", f64, f64, binary, floating, 0xa0)
WASM_OPCODE("f64.sub", f64, f64, binary, floating, 0xa1)
WASM_OPCODE("f64.mul", f64, f64, binary, floating, 0xa2)
WASM_OPCODE("f64.div", f64, f64, binary, floating, 0xa3)
WASM_OPCODE("f64.min", f64, f64, binary, floating, 0xa4)
WASM_OPCODE("f64.max", f64, f64, binary, floating, 0xa5)
WASM_OPCODE("f64.copysign", f64, f64, binary, floating, 0xa6)

WASM_OPCODE("i32.wrap_i64", i64, i32, conv, agnostic, 0xa7)
WASM_OPCODE("i32.trunc_s_f32", f32, i32, conv, signed, 0xa8)
WASM_OPCODE("i32.trunc_u_f32", f32, i32, conv, unsigned, 0xa9)
WASM_OPCODE("i32.trunc_s_f64", f64, i32, conv, signed, 0xaa)
WASM_OPCODE("i32.trunc_u_f64", f64, i32, conv, unsigned, 0xab)
WASM_OPCODE("i64.extend_s_i32", i32, i64, conv,   signed, 0xac)
WASM_OPCODE("i64.extend_u_i32", i32, i64, conv, unsigned, 0xad)
WASM_OPCODE("i64.trunc_s_f32", f32, i64, conv, signed, 0xae)
WASM_OPCODE("i64.trunc_u_f32", f32, i64, conv, unsigned, 0xaf)
WASM_OPCODE("i64.trunc_s_f64", f64, i64, conv, signed, 0xb0)
WASM_OPCODE("i64.trunc_u_f64", f64, i64, conv, unsigned, 0xb1)

WASM_OPCODE("f32.convert_s_i32", i32, f32, conv, signed, 0xb2)
WASM_OPCODE("f32.convert_u_i32", i32, f32, conv, unsigned, 0xb3)
WASM_OPCODE("f32.convert_s_i64", i64, f32, conv, signed, 0xb4)
WASM_OPCODE("f32.convert_u_i64", i64, f32, conv, unsigned, 0xb5)
WASM_OPCODE("f32.demote_f64", f64, f32, conv, floating, 0xb6)
WASM_OPCODE("f64.convert_s_i32", i32, f64, conv, signed, 0xb7)
WASM_OPCODE("f64.convert_u_i32", i32, f64, conv, unsigned, 0xb8)
WASM_OPCODE("f64.convert_s_i64", i64, f64, conv, signed, 0xb9)
WASM_OPCODE("f64.convert_u_i64", i64, f64, conv, unsigned, 0xba)
WASM_OPCODE("f64.promote_f32", f32, f64, conv, floating, 0xbb)

WASM_OPCODE("i32.reinterpret_f32", f32, i32, conv, agnostic, 0xbc)
WASM_OPCODE("i64.reinterpret_f64", f64, i64, conv, agnostic, 0xbd)
WASM_OPCODE("f32.reinterpret_i32", i32, f32, conv, agnostic, 0xbe)
WASM_OPCODE("f64.reinterpret_i64", i64, f64, conv, agnostic, 0xbf)

WASM_OPCODE("signature", void, void, signature, agnostic, 0x60)
