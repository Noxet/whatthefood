project(
  'what-the-food',
  'cpp',
  version : '0.1.0',
  default_options : [
    'cpp_std=c++17',
    'warning_level=3',
  ],
)

cpp = meson.get_compiler('cpp')

imgui_dir = 'vendor/imgui'

imgui_sources = files(
  imgui_dir / 'imgui.cpp',
  imgui_dir / 'imgui_draw.cpp',
  imgui_dir / 'imgui_tables.cpp',
  imgui_dir / 'imgui_widgets.cpp',
  imgui_dir / 'imgui_demo.cpp', # remove later if you don't want demo window
  imgui_dir / 'backends/imgui_impl_glfw.cpp',
  imgui_dir / 'backends/imgui_impl_opengl3.cpp',
)

imgui_inc = include_directories(
  imgui_dir,
  imgui_dir / 'backends',
)

glfw_inc = include_directories('vendor/GLFW/include')
glfw_lib = cpp.find_library(
  'glfw3',
  dirs: [meson.project_source_root() / 'vendor/GLFW/lib-mingw-w64'],
  static : true,
  required : true
)

opengl_dep = []
if host_machine.system() == 'linux'
  opengl_dep = cpp.find_library('GL', required : true)
elif host_machine.system() == 'windows'
  opengl_dep = cpp.find_library('opengl32', required : true)
elif host_machine.system() == 'darwin'
  opengl_dep = cpp.find_library('OpenGL', required : true)
endif

executable(
  'what-the-food',
  ['src/main.cpp', imgui_sources],
  include_directories : [imgui_inc, glfw_inc],
  dependencies : [glfw_lib, opengl_dep],
)
