def apply(config, args):
    config["baseimg"] = "disk/SLPS_015.56"
    config["myimg"] = "build/SLPS_015.56"
    config["mapfile"] = "build/lsdde.map"
    config["source_directories"] = ["src/lsdde"]
    # config["show_line_numbers_default"] = True
    config["arch"] = "mipsel"
    # config["map_format"] = "gnu" # gnu, mw, ms
    # config["build_dir"] = "build/" # only needed for mw and ms map format
    # config["expected_dir"] = "expected/" # needed for -o
    # config["makeflags"] = []
    # config["objdump_executable"] = ""
