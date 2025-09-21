#!/bin/bash

# 创建持久化目录结构
mkdir -p /home/coder/.local/share/code-server
mkdir -p /home/coder/.config/code-server
mkdir -p /home/coder/project

# 设置默认配置
cat > /home/coder/.config/code-server/config.yaml << 'EOF'
bind-addr: 0.0.0.0:8080
auth: none
cert: false
EOF

# 安装常用扩展的函数
install_extensions() {
    echo "开始安装扩展..."
    
    # 扩展列表
    local extensions=(
        "ms-python.python"
        "ms-vscode.vscode-typescript-next"
        "ms-vscode.cpptools"
        “catppuccin.catppuccin-vsc”
        "eamodio.gitlens"
        "formulahendry.auto-rename-tag"
        "yzhang.markdown-all-in-one"
        "foam.foam-vscode"
        "llvm-vs-code-extensions.vscode-clangd"
    )
    
    for extension in "${extensions[@]}"; do
        echo "安装: $extension"
        code-server --install-extension "$extension" --force
    done
    
    echo "扩展安装完成"
}

# 执行扩展安装
install_extensions

# 启动code-server
echo "启动 code-server..."
exec code-server --bind-addr 0.0.0.0:$PORT --auth none